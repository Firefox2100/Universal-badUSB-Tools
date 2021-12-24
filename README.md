# Universal-badUSB-Tools

> This repository holds codes for education and research purposes only, and is listed under GPL V3.0 License. This repository is provided "as is" with no warrenty. Neither me nor any other contributor of this code is responsible of any kind damage caused by use or misuse of this code.

EN/[CH](README_CH.md)

## Introduction

This is a project to implement a "universal tool" for badUSB development, allowing developers to use one single platform and development format to work on different hardwares, and users to use a simple and understandable format of scripts to customize their badUSB, without needing to worry about complicated methods to deal with specific hardware. As can be forseen, this means a lot of work, so this is a long-term project. I'll work on it when I'm avaliable, and I welcome any form of help, including but not limited to debugging, coding assists, and new ideas. Financial support is **unecessary** and will **not** be accepted, unless you would like this tool to deal with some specific and expensive hardware.

### Final form

> This is only an assumption and idea of the final form of this project. It may change anytime. Feel free to email me about any new ideas.

The final form of this project consists three parts.

- A **Program** using a specific format of scripts, which will generate the required source code for some hardware configuration. For example, user could supply it with a script, and command it to generate a ``*.ino`` source file for DigiSpark, or a ``*.c`` file for STM32.
- An **Invironment image** that contains necessary tools for most badUSB development senario. Normally a Docker image would surfice, but Docker on Windows can't access the Serial devices plugged in the host system, so it can't be used to flash the firmware directly. I'll continue to explore other options.
- A **Script** to manage everything. This script handles user input and calling of all the tools and program mentioned above.

### Current status

This project started recently. No features functional.

## badUSB support

There're many different types of badUSB avaliable, and many more hardware implementations that can be turned into a badUSB. Each of them requires specific adaptation of this project, so unfortunately I can't make it compatible with everything at once. The badUSB supported and I have plans to support is listed below.

Supported devices:

- None

Will be supported in the future:

- Rubber Ducky
- WHID Injector
- CJMCU 3212
- DigiSpark and all its direct variations
- STM32F103C8T6 based devices
- Xu (by @取火的普罗米修斯的GitHub)

Since many devices have special features (wireless connection and command, internal storage media, payload hardware switch, etc.), the program and script format will continue to update to support more devices. Please read the latest version of documents to understand the script format.

## Documents

Please refer to [these documents](docs/index.md).

## Issue and pull requests

You do not need any permission to create an issue or pull request, but please be sensible while doing so. Read the documents thoroughly and Googling your question normally helps with a lot of errors. If there's something you really need to open an issue about, please discribe in detail your actions, expected results, and what you've got instead. Preferably post with all relevant logs/echos/commands/screenshots in a readable format. If you'd like to open a pull request to help with this project in any ways, I'm more than grateful. Just be sure to test your modifications before opening one.
