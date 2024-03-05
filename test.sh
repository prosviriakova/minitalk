#!/bin/bash

# сheck argument
if [ $# -eq 0 ]; then
    echo "Usage: $0 <Server PID>"
    exit 1
fi

SERVER_PID=$1
CLIENT="./client"

send_and_measure() {
    local message=$1
    echo "Test with a message of length ${#message} characters:"
    printf '    '
    { time $CLIENT $SERVER_PID "$message"; } 2>&1 | tr '\n' ' '
    echo
}

# 10-character
send_and_measure "Let's go! "

# 100-character
send_and_measure "Success is not final, failure is not fatal: it is the courage to continue that counts. Pursue your dreams!"

# emojis
send_and_measure "🌍 🌵 🐱 🐉 🍣 🎼 🕌 🎩 🍉"

# generate and enter here dummy text
send_and_measure "Far far away, behind the word mountains, far from the countries Vokalia and Consonantia, there live."