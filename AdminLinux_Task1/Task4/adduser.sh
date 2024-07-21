#!/bin/bash

USER_NAME="nada1"
GROUP_NAME="mohamed"

# Check if group exists, if not, create it
if getent group "$GROUP_NAME" >/dev/null; then
  echo "Group $GROUP_NAME already exists."
else
  sudo groupadd "$GROUP_NAME"
  echo "Group $GROUP_NAME created."
fi

# Check if user exists, if not, create it and add to group
if id "$USER_NAME" &>/dev/null; then
  echo "User $USER_NAME already exists."
else
  sudo useradd -m -g "$GROUP_NAME" "$USER_NAME"
  echo "User $USER_NAME created and added to group $GROUP_NAME."
fi

# Display user and group information
echo "User information for $USER_NAME:"
id "$USER_NAME"
echo "Group information for $GROUP_NAME:"
getent group "$GROUP_NAME"

