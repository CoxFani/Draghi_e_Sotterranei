//
// Created by alpacox on 26/11/21.
//

#include "precompiler.h"
#include "SkillComponent.h"

/**************************  SKILL  ***************************/

SkillComponent::Skill::Skill(int type) {

    this->level = 1;
    this->levelCap = 99;
    this->exp = 0;
    this->expNext = 100;
}

SkillComponent::Skill::~Skill() {

}

const int SkillComponent::Skill::getType() const {
    return this->type;
}

const int &SkillComponent::Skill::getLevel() const {
    return this->level;
}

const int &SkillComponent::Skill::getExp() const {
    return this->exp;
}

const int &SkillComponent::Skill::getExpNext() const {
    return this->expNext;
}

void SkillComponent::Skill::setLevel(const int level) {

    this->level = level;
}

void SkillComponent::Skill::setLevelCap(const int level_Cap) {

    this->levelCap = level_Cap;
}


void SkillComponent::Skill::gainExp(const int exp) {

    this->exp += exp;
    this->updateLevel();
}

void SkillComponent::Skill::loseExp(const int exp) {

    this->exp -= exp;
}

void SkillComponent::Skill::updateLevel(const bool up) {

    /**
     * Aumenta o diminuisce il livello della skill a seconda che ci sia un deficit di exp o no.
     */

    if ( up ){
        if( this->level < this->levelCap){

            while (this->exp >= this->expNext){

                if ( this->level < this->levelCap){

                    this->level++;
                    this->expNext = static_cast<int>(std::pow(this->level, 2) + this->level * 10 + this->level * 2);
                }
            }
        }
    }
    else{
        if( this->level > 0){

            while (this->exp < 0){

                if ( this->level > 0){

                    this->level--;
                    this->expNext = static_cast<int>(std::pow(this->level, 2) + this->level * 10 + this->level * 2);
                }
            }
        }
    }



}

void SkillComponent::Skill::update() {

}



/**************************  SKILL COMPONENT  ***************************/



SkillComponent::SkillComponent() {

  this->skills.push_back(Skill(SKILLS::HEALTH));
  this->skills.push_back(Skill(SKILLS::ATTACK));
  this->skills.push_back(Skill(SKILLS::ACCURACY));
  this->skills.push_back(Skill(SKILLS::ENDURANCE));
}

SkillComponent::~SkillComponent() {

}

const int SkillComponent::getSkill(const int skill) const {

    if(skills.empty() || skill < 0 || skill >= this->skills.size())
        throw("ERROR::SKILLCOMPONENT::GETSKILL::SKILL DOES NOT EXIST: " + skill);
    else
        return this->skills[skill].getLevel();
}

const void SkillComponent::gainExp(const int skill, const int exp) {

    if(skills.empty() || skill < 0 || skill >= this->skills.size())
        throw("ERROR::SKILLCOMPONENT::GAINEXP::SKILL DOES NOT EXIST: " + skill);
    else{
        this->skills[skill].gainExp(exp);
    }
}
