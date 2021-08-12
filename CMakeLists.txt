cmake_minimum_required(VERSION 3.16)
project(Draghi_e_Sotterranei)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Draghi_e_Sotterranei main.cpp Enemy.cpp Enemy.h GameCharacter.cpp GameCharacter.h Weapon.cpp Weapon.h Dice.cpp Dice.h Hero.cpp Hero.h Warrior.cpp Warrior.h Archer.cpp Archer.h Mage.cpp Mage.h Orc.cpp Orc.h Skeleton.cpp Skeleton.h Troll.cpp Troll.h EvilMage.cpp EvilMage.h Zombie.cpp Zombie.h MartialWeapon.cpp MartialWeapon.h RangedWeapon.cpp RangedWeapon.h MagicalWeapon.cpp MagicalWeapon.h Observer.h Factory.cpp Factory.h Subject.h TileMap.cpp TileMap.h Map.cpp Map.h State.cpp State.h GameState.cpp GameState.h Game.cpp Game.h)
target_link_libraries(Draghi_e_Sotterranei sfml-graphics sfml-audio)
