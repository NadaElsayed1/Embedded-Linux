#!/bin/bash

# The -f option in the if statement checks if .bashrc file exists in my home directory
if [ -f "$HOME/.bashrc" ]; then
  # export HELLO=\$HOSTNAME: This sets an environment variable named HELLO 
  # to the value of the environment variable HOSTNAME
  # >> "$HOME/.bashrc": This appends the output of the echo command to the .bashrc file in the user's home directory.
  echo "export HELLO=\$HOSTNAME" >> "$HOME/.bashrc"

  # The backslash (\) before the dollar sign ($) ensures that the dollar sign is treated as a literal character in the echo command,
  # so that whoami is not executed when the echo command is run.
  echo "LOCAL=\$(whoami)" >> "$HOME/.bashrc"
  echo "echo \$LOCAL" >> "$HOME/.bashrc"  # This is to print my username when new terminal open
fi

#Then open another terminal
# The command gnome-terminal & is used to open a new GNOME terminal window in the background.
# &: This symbol runs the preceding command in the background.
gnome-terminal &