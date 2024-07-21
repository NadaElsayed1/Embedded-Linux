#!/bin/bash

USER_NAME="nada1"

# Lock user account
if id "$USER_NAME" &>/dev/null; then
  sudo usermod -L "$USER_NAME"
  echo "User $USER_NAME account has been locked."
else
  echo "User $USER_NAME does not exist."
fi

