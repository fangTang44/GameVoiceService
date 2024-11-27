#ifndef SENDER_HPP
#define SENDER_HPP

#include <string>

class Sender
{
private:
  std::string m_sEmailAddress;
public:
  /// @brief 构造Sender
  Sender();

  /// @brief 
  /// @param emailAddress 用于初始化要发送邮件的用户的地址
  Sender(std::string emailAddress);
};
#endif