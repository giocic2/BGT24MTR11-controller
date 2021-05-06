#!/bin/sh
# This script is used to update the repository: it discards changes, pulls, and makes the Python script executable.
git reset --hard
git pull
chmod +x BGT24MTR11_controller.py
