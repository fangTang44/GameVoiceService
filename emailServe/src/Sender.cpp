#include "Sender.hpp"

Sender::Sender() {
  m_sEmailAddress = "";
}

Sender::Sender(std::string emailAddress) : m_sEmailAddress(emailAddress) {
}
