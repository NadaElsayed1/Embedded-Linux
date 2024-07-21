#!/bin/bash

GROUP_NAME="mohamed"

# Delete group
if getent group "$GROUP_NAME" >/dev/null; then
  sudo groupdel "$GROUP_NAME"
  echo "Group $GROUP_NAME has been deleted."
else
  echo "Group $GROUP_NAME does not exist."
fi

