#include "Logger.h"

#define OUT "OUT::"
#define IN "IN::"
#define IN_LENGTH 4

void Logger::sendMsg(String msg) { Serial.println(OUT + msg); }

void Logger::sendMsg(float temp) {
    Serial.print(OUT);
    Serial.print("T:");
    Serial.println(temp);
}

void Logger::sendMsg(int fullness) {
    Serial.print(OUT);
    Serial.print("W:");
    Serial.println(fullness);
}

String Logger::getMsg() {
    if (Serial.available() > 0) {
        String msg = Serial.readString();
        if (msg.startsWith(IN)) {
            return msg.endsWith("\n")
                       ? msg.substring(IN_LENGTH, msg.length() - 1)
                       : msg.substring(IN_LENGTH);
        }
    }

    return "";
}
