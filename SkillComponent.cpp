//
// Created by alpacox on 26/11/21.
//

#include "precompiler.h"
#include "SkillComponent.h"

/**************************  SKILL  ***************************/

SkillComponent::Skill::Skill(int type) {
    level = 1;
    levelCap = 99;
    exp = 0;
    expNext = 100;
}

SkillComponent::Skill::~Skill() {

}

const int SkillComponent::Skill::getType() const {
    return type;
}

const int &SkillComponent::Skill::getLevel() const {
    return level;
}

const int &SkillComponent::Skill::getExp() const {
    return exp;
}

const int &SkillComponent::Skill::getExpNext() const {
    return expNext;
}

void SkillComponent::Skill::setLevel(const int level) {
    this->level = level;
}

void SkillComponent::Skill::setLevelCap(const int level_Cap) {
    this->levelCap = level_Cap;
}


void SkillComponent::Skill::gainExp(const int exp) {
    this->exp += exp;
    updateLevel();
}

void SkillComponent::Skill::loseExp(const int exp) {
    this->exp -= exp;
}

void SkillComponent::Skill::updateLevel(const bool up) {

    /**
     * Aumenta o diminuisce il livello della skill a seconda che ci sia un deficit di exp o no.
     */

    if (up){
        if(level < levelCap){
            while (exp >= expNext){
                if (level < levelCap){
                    level++;
                    expNext = static_cast<int>(std::pow(level, 2) + level * 10 + level * 2);
                }
            }
        }
    }
    else{
        if(level > 0){
            while (exp < 0){
                if (level > 0){
                    level--;
                    expNext = static_cast<int>(std::pow(level, 2) + level * 10 + level * 2);
                }
            }
        }
    }
}

void SkillComponent::Skill::update() {

}


/**************************  SKILL COMPONENT  ***************************/


SkillComponent::SkillComponent() {

  skills.push_back(Skill(SKILLS::HEALTH));
  skills.push_back(Skill(SKILLS::ATTACK));
  skills.push_back(Skill(SKILLS::ACCURACY));
  skills.push_back(Skill(SKILLS::ENDURANCE));
}

SkillComponent::~SkillComponent() {

}

const int SkillComponent::getSkill(const int skill) const {
    if(skills.empty() || skill < 0 || skill >= skills.size())
        throw("ERROR::SKILLCOMPONENT::GETSKILL::SKILL DOES NOT EXIST: " + skill);
    else
        return skills[skill].getLevel();
}

const void SkillComponent::gainExp(const int skill, const int exp) {
    if(skills.empty() || skill < 0 || skill >= skills.size())
        throw("ERROR::SKILLCOMPONENT::GAINEXP::SKILL DOES NOT EXIST: " + skill);
    else{
        skills[skill].gainExp(exp);
    }
}
