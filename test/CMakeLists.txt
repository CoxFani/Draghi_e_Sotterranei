cmake_minimum_required(VERSION 3.16)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
set(TEST_SOURCE_FILES runAllTests.cpp EnemyTest.cpp HeroTest.cpp ../Enemy.cpp ../Enemy.h ../GameCharacter.cpp ../GameCharacter.h ../Weapon.cpp ../Weapon.h ../Hero.cpp ../Hero.h ../TileMap.cpp ../TileMap.h ../State.cpp ../State.h ../GameState.cpp ../GameState.h ../Game.cpp ../Game.h ../MainMenuState.cpp ../MainMenuState.h ../Gui.cpp ../Gui.h ../MovementComponent.cpp ../MovementComponent.h ../AnimationComponent.cpp ../AnimationComponent.h ../EditorState.cpp ../EditorState.h ../HitboxComponent.cpp ../HitboxComponent.h ../Tile.cpp ../Tile.h ../PauseMenu.cpp ../PauseMenu.h ../SettingState.cpp ../SettingState.h ../GraphicsSettings.cpp ../GraphicsSettings.h ../precompiler.h ../AttributeComponent.cpp ../AttributeComponent.h ../HeroGUI.cpp ../HeroGUI.h ../Item.cpp ../Item.h ../MeleeWeapon.cpp ../MeleeWeapon.h ../Sword.cpp ../Sword.h ../SkillComponent.cpp ../SkillComponent.h ../EnemySpawnerTile.cpp ../EnemySpawnerTile.h ../EditorMode.cpp ../EditorMode.h ../DefaultEditorMode.cpp ../DefaultEditorMode.h ../EnemyEditorMode.cpp ../EnemyEditorMode.h ../EditorModes.h ../RegularTile.cpp ../RegularTile.h ../EnemyFactory.cpp ../EnemyFactory.h ../Items.h ../TextTagSystem.cpp ../TextTagSystem.h ../HeroTabs.cpp ../HeroTabs.h ../CharacterTab.cpp ../CharacterTab.h ../Tab.cpp ../Tab.h ../EnemyStrategy.cpp ../EnemyStrategy.h ../AttackStrategy.cpp ../AttackStrategy.h ../DistanceCalc.cpp ../DistanceCalc.h ../Observer.h ../Achievements.h ../Subject.h ../GameManager.h)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_precompile_headers(runAllTests PUBLIC ../precompiler.h)
target_link_libraries(runAllTests gtest gtest_main sfml-graphics sfml-audio)