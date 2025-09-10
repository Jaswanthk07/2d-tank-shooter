# 2D Tank Shooter Game 🪖

A dynamic 2D shooting game built with OpenGL and GLUT, featuring tank combat mechanics, enemy AI, and engaging gameplay with smooth animations and visual effects.

## 🎮 Game Overview

The 2D Tank Shooter is an action-packed arcade-style game where players control a tank to survive against enemy forces. Navigate through the battlefield, destroy enemy tanks to earn points, or strategically dodge them to stay alive. The game combines classic arcade gameplay with OpenGL graphics rendering techniques.

### Key Features
- **Dynamic Tank Combat**: Control your tank with responsive WASD movement
- **Enemy AI System**: Face intelligent enemy tanks with collision detection
- **Scoring System**: Earn 20 points for destroying enemies, 10 points for dodging
- **Visual Effects**: Gradient backgrounds and smooth animations
- **Game States**: Welcome screen, gameplay, and game-over screens
- **Pause Functionality**: Pause and resume gameplay at any time

## 🚀 Tech Stack

### Core Technologies
- **Language**: C++
- **Graphics Library**: OpenGL
- **Windowing System**: GLUT (OpenGL Utility Toolkit)
- **Development Platform**: Cross-platform compatible

### OpenGL Components Used
- **Window Management**: `glutInit()`, `glutCreateWindow()`, `glutMainLoop()`
- **Event Handling**: `glutDisplayFunc()`, `glutKeyboardFunc()`, `glutMouseFunc()`
- **Graphics Rendering**: `glClearColor()`, `glColor3f()`, `glColor3ub()`
- **Transformations**: `glTranslatef()`, `glRotatef()`, `glScalef()`
- **Matrix Operations**: `glPushMatrix()`, `glPopMatrix()`, `glLoadIdentity()`
- **2D Projection**: `gluOrtho2D()`, `glViewport()`
- **Geometry Rendering**: `glBegin()`, `glEnd()`, `glVertex2i()`

## 🎯 Game Mechanics

### Player Controls
- **W**: Move tank forward
- **A**: Move tank left
- **S**: Move tank backward
- **D**: Move tank right
- **Space**: Fire projectiles
- **P**: Pause/Resume game
- **Mouse**: Navigate menus and start game

### Gameplay Features
- **Boundary Detection**: Tanks cannot move outside the game area
- **Collision System**: Comprehensive collision detection between player, enemies, and projectiles
- **Dynamic Enemy Generation**: Random enemy tank spawning with overlap prevention
- **Projectile System**: Bullet physics with hit detection and cleanup
- **Score Tracking**: Real-time score updates with different point values

## 🏗️ System Architecture

### Core Components

#### 1. Game State Management
- **Welcome Screen**: Game introduction and controls
- **Game Screen**: Main gameplay with HUD display
- **Game Over Screen**: Score display and restart options

#### 2. Tank System
- **Player Tank**: User-controlled tank with movement and shooting capabilities
- **Enemy Tanks**: AI-controlled tanks with random movement patterns
- **Collision Detection**: Tank-to-tank collision handling

#### 3. Projectile System
- **Bullet Management**: Dynamic bullet creation, movement, and destruction
- **Hit Detection**: Collision detection between bullets and enemy tanks
- **Memory Optimization**: Automatic cleanup of off-screen projectiles

#### 4. Rendering Engine
- **2D Graphics Pipeline**: OpenGL-based rendering system
- **UI Components**: HUD display, menus, and game elements
- **Visual Effects**: Gradient backgrounds and smooth animations

## 📋 Implementation Details

### Key Functions

#### Game Initialization
```cpp
myInit()           // OpenGL environment setup
main()             // Game integration and startup
```

#### Player Mechanics
```cpp
keyboard()         // Input handling for player movement and shooting
drawTank()         // Tank rendering for both player and enemies
tankCollision()    // Player-enemy collision detection
```

#### Enemy System
```cpp
generate_tank()    // Enemy tank spawning with position randomization
translate()        // Enemy movement and boundary reset logic
opponentCollision() // Enemy overlap prevention
```

#### Projectile System
```cpp
fireCollision()    // Bullet-enemy collision detection and scoring
fire.push_back()   // Bullet creation and management
```

#### UI and Display
```cpp
welcomeScreen()    // Initial game interface
gameScreen()       // Main gameplay display
overScreen()       // Game over interface
drawHUD()          // Score and game info display
```

## 🛠️ Installation and Setup Guide

### System Requirements
- **Operating System**: Windows 10/11, macOS 10.14+, or Linux (Ubuntu 18.04+)
- **RAM**: Minimum 2GB
- **Graphics**: OpenGL 2.1 compatible graphics card
- **Storage**: 50MB free disk space

### Prerequisites

#### For Windows:
- **Visual Studio 2019/2022** or **MinGW-w64**
- **Git** for version control
- **OpenGL** (usually pre-installed)
- **GLUT/FreeGLUT** library

#### For Linux (Ubuntu/Debian):
- **GCC compiler**
- **Git**
- **OpenGL development libraries**
- **GLUT development libraries**

#### For macOS:
- **Xcode Command Line Tools**
- **Git**
- **OpenGL** (pre-installed)
- **GLUT** (pre-installed)

### Step-by-Step Installation

#### 🖥️ **Windows Installation**

##### Option 1: Using Visual Studio (Recommended)

1. **Install Visual Studio Community 2022**
   ```
   Download from: https://visualstudio.microsoft.com/downloads/
   Select "Desktop development with C++" workload during installation
   ```

2. **Install FreeGLUT**
   ```bash
   # Using vcpkg (recommended)
   git clone https://github.com/Microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
   .\vcpkg integrate install
   .\vcpkg install freeglut:x64-windows
   ```

3. **Clone the Repository**
   ```bash
   git clone https://github.com/Jaswanthk07/2d-tank-shooter.git
   cd 2d-tank-shooter
   ```

4. **Open in Visual Studio**
   - Create new C++ Console Application
   - Replace main.cpp with project files
   - Add include directories and library dependencies
   - Build and run (F5)

##### Option 2: Using MinGW-w64

1. **Install MinGW-w64**
   ```
   Download from: https://www.mingw-w64.org/downloads/
   Add MinGW bin folder to PATH environment variable
   ```

2. **Install FreeGLUT**
   ```bash
   # Download FreeGLUT binaries for MinGW
   # Extract to MinGW folder structure
   ```

3. **Clone and Compile**
   ```bash
   git clone https://github.com/Jaswanthk07/2d-tank-shooter.git
   cd 2d-tank-shooter
   g++ -o tank_shooter.exe main.cpp -lfreeglut -lopengl32 -lglu32
   ```

4. **Run the Game**
   ```bash
   ./tank_shooter.exe
   ```

#### 🐧 **Linux Installation (Ubuntu/Debian)**

1. **Update Package Manager**
   ```bash
   sudo apt update
   sudo apt upgrade
   ```

2. **Install Required Packages**
   ```bash
   sudo apt install build-essential git
   sudo apt install freeglut3-dev libglu1-mesa-dev mesa-common-dev
   sudo apt install libgl1-mesa-dev
   ```

3. **Clone the Repository**
   ```bash
   git clone https://github.com/Jaswanthk07/2d-tank-shooter.git
   cd 2d-tank-shooter
   ```

4. **Compile the Project**
   ```bash
   g++ -o tank_shooter main.cpp -lGL -lGLU -lglut
   ```

5. **Make Executable and Run**
   ```bash
   chmod +x tank_shooter
   ./tank_shooter
   ```

#### 🍎 **macOS Installation**

1. **Install Xcode Command Line Tools**
   ```bash
   xcode-select --install
   ```

2. **Install Homebrew (if not already installed)**
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

3. **Install Git (if not already installed)**
   ```bash
   brew install git
   ```

4. **Clone the Repository**
   ```bash
   git clone https://github.com/Jaswanthk07/2d-tank-shooter.git
   cd 2d-tank-shooter
   ```

5. **Compile the Project**
   ```bash
   g++ -o tank_shooter main.cpp -framework OpenGL -framework GLUT
   ```

6. **Run the Game**
   ```bash
   ./tank_shooter
   ```

### Alternative Installation Methods

#### Using Code::Blocks IDE

1. **Install Code::Blocks**
   ```
   Download from: http://www.codeblocks.org/downloads
   ```

2. **Create New Project**
   - File → New → Project → OpenGL/GLUT project
   - Copy source code to main.cpp
   - Build and run

#### Using Dev-C++

1. **Install Dev-C++**
   ```
   Download from: https://www.bloodshed.net/devcpp.html
   ```

2. **Setup OpenGL**
   - Tools → Package Manager → Install OpenGL package
   - Create new project and add source files

### 🚨 Troubleshooting

#### Common Issues and Solutions

**Issue 1: "Cannot find -lglut" error**
```bash
# Linux solution:
sudo apt install freeglut3-dev

# Windows solution:
# Ensure FreeGLUT is properly installed and linked
```

**Issue 2: "GL/glut.h not found"**
```bash
# Install development headers
sudo apt install mesa-common-dev libgl1-mesa-dev
```

**Issue 3: Black screen or no display**
```bash
# Update graphics drivers
# Ensure OpenGL 2.1+ support
```

**Issue 5: Pre-compiled executable not working**
```bash
# The executable might not be compatible with your system
# Recompile from source:

# Windows (MinGW)
g++ -o new_tankshooter.exe main.cpp -lfreeglut -lopengl32 -lglu32

# Linux
g++ -o new_tankshooter main.cpp -lGL -lGLU -lglut

# macOS
g++ -o new_tankshooter main.cpp -framework OpenGL -framework GLUT
```

**Issue 6: Code::Blocks build errors**
```bash
# Ensure proper library linking in Project → Build Options
# Windows: Add opengl32, glu32, freeglut
# Linux: Add GL, GLU, glut
# macOS: Add OpenGL and GLUT frameworks
```

**Issue 7: Missing OpenGL libraries**
```bash
# Verify OpenGL installation
# Windows: Ensure graphics drivers are updated
# Linux: sudo apt install mesa-utils && glxinfo | grep OpenGL
# macOS: OpenGL should be pre-installed with system
```

### 📁 Project Structure
```
2d-tank-shooter/
│
├── main.cpp              # Main game source file
├── README.md             # This file
├── LICENSE               # License file
├── screenshots/          # Game screenshots
│   ├── welcome_screen.png
│   ├── gameplay.png
│   └── gameover_screen.png
├── docs/                 # Documentation
└── build/                # Compiled binaries (created after build)
```

### ⚡ Quick Start Commands

```bash
# Clone repository
git clone https://github.com/Jaswanthk07/2d-tank-shooter.git
cd 2d-tank-shooter

# Linux/macOS compilation
g++ -o tank_shooter main.cpp -lGL -lGLU -lglut

# macOS alternative
g++ -o tank_shooter main.cpp -framework OpenGL -framework GLUT

# Windows (MinGW)
g++ -o tank_shooter.exe main.cpp -lfreeglut -lopengl32 -lglu32

# Run the game
./tank_shooter        # Linux/macOS
tank_shooter.exe      # Windows
```

### 🔧 Build Configuration

#### Makefile (Optional)
Create a `Makefile` for easier compilation:

```makefile
CC = g++
CFLAGS = -Wall -std=c++11
LIBS_LINUX = -lGL -lGLU -lglut
LIBS_MACOS = -framework OpenGL -framework GLUT
LIBS_WINDOWS = -lfreeglut -lopengl32 -lglu32
TARGET = tank_shooter
SOURCE = main.cpp

linux:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LIBS_LINUX)

macos:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LIBS_MACOS)

windows:
	$(CC) $(CFLAGS) -o $(TARGET).exe $(SOURCE) $(LIBS_WINDOWS)

clean:
	rm -f $(TARGET) $(TARGET).exe
```

Usage:
```bash
make linux    # For Linux
make macos    # For macOS
make windows  # For Windows
```

## 🎮 How to Play

1. **Start the Game**: Click "Start Game" on the welcome screen
2. **Control Your Tank**: Use WASD keys to move around the battlefield
3. **Combat**: Press Space to fire at enemy tanks
4. **Survive**: Avoid collisions with enemy tanks
5. **Score Points**: 
   - Destroy enemy tanks: +20 points
   - Dodge enemy tanks: +10 points
6. **Game Over**: Collision with enemy tanks ends the game
7. **Restart**: Click "Go Back" to return to the main menu

## 🏆 Scoring System

- **Enemy Destruction**: 20 points per enemy tank destroyed
- **Enemy Dodging**: 10 points per enemy tank successfully dodged
- **Survival Bonus**: Continuous gameplay increases overall score

## 🔧 Performance Optimizations

- **Frame Rate Control**: Consistent rendering with sleep mechanisms
- **Memory Management**: Automatic cleanup of off-screen elements
- **Collision Optimization**: Efficient boundary checking and collision detection
- **Vector Management**: Dynamic resizing of bullet and enemy arrays

## 📸 Screenshots

*Add your game screenshots here:*
- Welcome Screen
- Gameplay Screen
- Game Over Screen

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🎓 Educational Purpose

This project was developed as part of a Computer Graphics and Multimedia course, demonstrating:
- OpenGL graphics programming
- Game development fundamentals
- Real-time rendering techniques
- User interaction design
- Software architecture principles

## 🔮 Future Enhancements

- **Enhanced Enemy Mechanics**: More complex movement patterns and behaviors
- **Power-ups and Special Weapons**: Enhanced combat mechanics
- **Multiple Enemy Types**: Different tank varieties with varying movement speeds
- **Sound Effects and Background Music**: Audio enhancement
- **Multiplayer Support**: Local and online multiplayer modes
- **Level Progression System**: Multiple stages with increasing difficulty
- **Enhanced Visual Effects**: Particle systems and advanced animations
- **Customizable Controls**: Key remapping and control preferences

---

**Enjoy the game and happy coding!** 🚀
