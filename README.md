<div align="center">
  <h1>Double Planet Simulation</h1>
    <blockquote>
        <p><i>Round and round and round...</i></p>
        <p><b>Simulating orbital mechanics with planets using C++.</b></p>
        <img src=https://img.shields.io/badge/Build-Working-brightgreen>
        <img src=https://img.shields.io/badge/Progress-Complete-Green>
    </blockquote>
</div>

![alt text](https://github.com/KacperBazan/Planet-Simulation/blob/main/img/planet.jpg)

# Installation
## Raw Executable
If you just want the executable, navigate to the releases and unzip the ```.rar``` file. You should have both the ```.exe``` file that will run the project and the ```.dll``` files that are required to properly link to the executable.

## Building
I am still learning CMAKE, so for the time being, please build this using Visual Studio 2019.
1. Download this repository and unzip it. The root folder will be the folder with ```-main``` appended to the repository name.
2. Optional: You could delete the ```img``` folder, ```.gitattributes```, ```.gitignore```, and ```README.md``` if wanted.
3. Open Visual Studio 2019 and select **Continue without code** under the opening project options.
4. Navigate to the Menu. *File* → *New* → *Project from existing code*. Select the **Visual C++** option.
5. For *Project file location:*, select the root folder you downloaded.
6. For *Project name:*, name the project whatever you want. Select **Next**.
7. Select **Use Visual Studio**, and leave all settings. Select **Next**.
8. We will be including include and library paths later. Select **Finish**.
9. Navigate to the Solution Explorer on the left and open the ```main.cpp``` file located in ```src```.
10. Navigate to the Menu. *Project* → *[PROJECT NAME] Properties*.
11. Change the *Configuration* tab to **All Configurations**
12. Under the *C/C++* tab add the following lines to the *Additional Include Directories* section by clicking on the three dots at the end of the selection: ```$(SolutionDir)include```, ```$(SolutionDir)lib\SFML\include```.
13. Under the *Linker* tab, navigate to the *General* sub tab. Add the following line to the *Additional Library Dependencies* section by clicking on the three dots at the end of the selection: ```$(SolutionDir)lib\SFML\lib```.
14. Navigate to the *Input* sub tab within *Linker* and add the following dependencies to *Additional Dependencies*: ```sfml-graphics.lib```, ```sfml-window.lib```, ```sfml-audio.lib```, ```sfml-system.lib```, ```sfml-network.lib```.
15. Optional: If you're going to be debugging and changing this code, change the *Configuration* tab to **Debug** and change the additional dependencies so they have a ```-d``` prefix before ```.lib```. An example would be: ```sfml-graphics-d.lib```.
16. Switch back to **All Configurations** in the *Configuration* tab and navigate back to general project properties.
17. Under the *General* properties subtab, change the output directory to: ```$(SolutionDir)build\$(Configuration)```.
18. Under the *General* properties subtab, change the intermediate directory to: ```$(SolutionDir)build\Intermediate```
19. Build the project once by right-clicking on the project and selecting **Build**.
20. You should get an error, but you will get an ```.exe``` in the specified build folder.
21. We need the ```.dll``` files from the SFML library. Download the library [here](https://www.sfml-dev.org/files/SFML-2.5.1-windows-vc15-32-bit.zip).
22. Unzip and navigate to the ```bin``` folder.
23. Copy all the ```.dll``` files and paste them in the same folder where the project ```.exe``` is.
24. Rebuild one more time.




