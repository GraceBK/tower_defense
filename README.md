# projet_cpp développé sur Xcode

Projet de C++ 2017-2018 (Vaisseaux contre Astéroïdes)

Développé sous macOS High Sierra l'IDE utilisé est Xcode (Version 9.2)

## Pour compiler et tester

	Xcode (dernière version de préférence)

où encore dans un terminal aller dans le répertoire contenant les sources (projet_cpp/projet_cpp)
et utiliser les commande suivante:

	make veryclean
	make mac
	make run

## Hiérarchie et contenu du repertoire projet_cpp (résultat de la commande tree projet_cpp)

	projet_cpp/
	├── README.md
	├── doc
	│   ├── Rapport_CPP.pdf
	│   ├── diagram_class.png
	│   └── diagram_class2.png
	├── libEngine.a
	├── projet_cpp
	│   ├── bin
	│   │   └── save_partie.txt
	│   ├── doc
	│   │   ├── Rapport_CPP.pdf
	│   │   ├── diagram_class.png
	│   │   └── diagram_class2.png
	│   ├── include
	│   │   ├── Asteroids.hpp
	│   │   ├── Asteroids1.hpp
	│   │   ├── Asteroids2.hpp
	│   │   ├── Case.hpp
	│   │   ├── ControlEngine.h
	│   │   ├── Damier.hpp
	│   │   ├── Engine.h
	│   │   ├── GL
	│   │   │   └── glut.h
	│   │   ├── Game.hpp
	│   │   ├── GameEngine.h
	│   │   ├── GraphicEngine.h
	│   │   ├── GraphicPrimitives.h
	│   │   ├── Missile.hpp
	│   │   ├── MyControlEngine.h
	│   │   ├── MyGameEngine.h
	│   │   ├── MyGraphicEngine.h
	│   │   ├── Stopwatch.h
	│   │   ├── Vaisseaux.hpp
	│   │   ├── Vaisseaux1.hpp
	│   │   ├── Vaisseaux2.hpp
	│   │   ├── all_others.hpp
	│   │   └── libGraphicInclude.h
	│   ├── libLinux
	│   │   └── libEngine.a
	│   ├── libMac
	│   │   └── libEngine.a
	│   ├── libWin
	│   │   ├── engineVS2012.zip
	│   │   ├── engineVS2013.zip
	│   │   ├── engineVS2015.zip
	│   │   ├── glut.def
	│   │   ├── glut32.dll
	│   │   ├── glut32.lib
	│   │   └── libEngine.a
	│   ├── makefile
	│   ├── run.sh
	│   └── src
	│       ├── Asteroids.cpp
	│       ├── Asteroids1.cpp
	│       ├── Asteroids2.cpp
	│       ├── Case.cpp
	│       ├── Damier.cpp
	│       ├── Game.cpp
	│       ├── Missile.cpp
	│       ├── MyControlEngine.cpp
	│       ├── MyGameEngine.cpp
	│       ├── MyGraphicEngine.cpp
	│       ├── Vaisseaux.cpp
	│       ├── Vaisseaux1.cpp
	│       ├── Vaisseaux2.cpp
	│       ├── all_others.cpp
	│       └── main.cpp
	└── projet_cpp.xcodeproj
	    ├── project.pbxproj
	    ├── project.xcworkspace
	    │   ├── contents.xcworkspacedata
	    │   └── xcuserdata
	    │       └── grace.xcuserdatad
	    │           └── UserInterfaceState.xcuserstate
    	└── xcuserdata
    	    └── grace.xcuserdatad
    	        ├── xcdebugger
    	        │   └── Breakpoints_v2.xcbkptlist
    	        └── xcschemes
    	            └── xcschememanagement.plist

	18 directories, 62 files