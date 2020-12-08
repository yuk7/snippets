#!/bin/bash
HOST=""
USER=""
PASS=""

UID=$(id -u)
GID=$(id -g)

sudo mount -t cifs //${HOST}/${USER}$ /mnt/ndrv -o "user=${USER},pass=${PASS},uid=${UID},gid=${GID},vers=2.1"