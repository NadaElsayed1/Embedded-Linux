#!/bin/bash

USER_NAME="nada1"

# Delete user account
if id "$USER_NAME" &>/dev/null; then
  sudo userdel -r "$USER_NAME"
  echo "User $USER_NAME account has been deleted."
else
  echo "User $USER_NAME does not exist."
fi

