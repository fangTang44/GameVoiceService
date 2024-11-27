#include <curl/curl.h>
#include <cstring>
#include <iostream>

size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userdata) {
    const char **payload = reinterpret_cast<const char **>(userdata);
    size_t buffer_size = size * nmemb;

    if (*payload && strlen(*payload)) {
        size_t len = strlen(*payload);
        size_t copy_len = len < buffer_size ? len : buffer_size;
        memcpy(ptr, *payload, copy_len);
        *payload += copy_len;
        return copy_len;
    }
    return 0;
}

int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        // 使用 SMTP 端口 465 并启用 SSL
        curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.163.com:465");

        // 登录凭证
        curl_easy_setopt(curl, CURLOPT_USERNAME, "18691171371@163.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "SYwXy68hJHvKjcUv");

        // 发件人
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "<18691171371@163.com>");

        // 收件人
        struct curl_slist *recipients = nullptr;
        recipients = curl_slist_append(recipients, "<18691171371@163.com>");
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // 邮件正文
        const char *payload_text =
            "To: 18691171371@163.com\r\n"
            "From: 18691171371@163.com\r\n"
            "Subject: Test Email\r\n"
            "Date: Thu, 30 Nov 2024 12:00:00 +0000\r\n"
            "\r\n"
            "This is a test email sent using libcurl.\r\n";

        // 通过 payload_source 提供邮件数据
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &payload_text);

        // 启用调试输出
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // 禁用 SSL 验证（避免证书验证警告）
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        // 禁用扩展命令，如 VRFY
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_MAIL_AUTH, "PLAIN");

        // 发送邮件
        res = curl_easy_perform(curl);

        // 检查结果
        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        // 清理
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    return 0;
}
