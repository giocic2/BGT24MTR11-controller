#!/bin/sh
# This script is used to update the repository: it discards changes, pulls, and makes the Python script executable.
cd BGT24MTR11_controller
git reset --hard
git pull
chmod +x BGT24MTR11_controller.py
