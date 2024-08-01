# Project Setup
- Project is created in Visual Studios and external libraries are installed using vcpkg. 
- Set up instructions: 
	- https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-packaging?pivots=shell-cmd
- Clone vcpkg 
	- `git clone https://github.com/microsoft/vcpkg.git`
- Execute the bootstrap-vcpkg.bat script to download the vcpkg executable. 
- Install the [external libraries](#el)
	- ./vcpkg.exe install curl
	- ./vcpkg.exe install nlohmann-json

# Environment Constraints
- Common issue: orderbookProject.exe - System Error
	- VCRUNTIME140_1D.dll was not found. 
	- Solution: Update Windows SDK version to 10.0.

# [External Libraries](#el)
- curl
- nlohmann/json

