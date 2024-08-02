# Introduction
This is my first C++ Project I have ever done. 

The goal is to build a Binance order book that will query binance.comfor the top 5 levels of bids or ask prices. After the user enters a Binance-style symbol, the app will query the API of binance for the required information. 

# Project Setup
- Project is done in Windows.
- Project is created in Visual Studios and external libraries are installed using vcpkg. 
- Set up instructions: 
	- https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-packaging?pivots=shell-cmd
- Clone vcpkg 
	- Open Developer Powershell for VS 2022 and run as administrator. 
	- `git clone https://github.com/microsoft/vcpkg.git`
- Execute the bootstrap-vcpkg.bat script to download the vcpkg executable. 
	- Enter the cloned folder
		- `cd vcpkg` 
	- Execute the bootstrap-vcpkg.bat file to install the vcpkg executable.
		- `./bootstrap-vcpkg.bat`
	- After the installation, execute the following command:
		- `.vcpkg.exe integrate install`
	- Install the [external libraries](#el)
		- ./vcpkg.exe install curl:x64-windows
		- ./vcpkg.exe install nlohmann-json

# Environment Constraints
- Windows SDK version 10.0 is required to execute this project. 
- Common issue: orderbookProject.exe - System Error
	- VCRUNTIME140_1D.dll was not found. 
	- Solution: Update Windows SDK version to 10.0.

# [External Libraries](#el)
- curl
- nlohmann/json

# Folder arrangements
- cpp files are stored in the src/ folder and the header files are stored in the include/ folder. 