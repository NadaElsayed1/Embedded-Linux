#!/bin/bash

GROUP_NAME="pgroup"
GROUP_ID="30000"

# Check if group exists, if not, create it with specific GID
if getent group "$GROUP_NAME" >/dev/null; then
  echo "Group $GROUP_NAME already exists."
else
  sudo groupadd -g "$GROUP_ID" "$GROUP_NAME"
  echo "Group $GROUP_NAME with GID $GROUP_ID created."
fi

