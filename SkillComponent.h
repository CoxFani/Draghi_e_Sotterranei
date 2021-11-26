//
// Created by alpacox on 26/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_SKILLCOMPONENT_H
#define DRAGHI_E_SOTTERRANEI_SKILLCOMPONENT_H

enum SKILLS{HEALTH = 0, ATTACK, ACCURACY, ENDURANCE};

class SkillComponent {

public:
    SkillComponent();
    virtual ~SkillComponent();

    const int getSkill(const int skill) const;
    const void gainExp(const int skill, const int exp);

private:
    class Skill{

    public:
        Skill(int type);
        ~Skill();

        const int getType() const;
        const int& getLevel() const;
        const int& getExp() const;
        const int& getExpNext() const;

        void setLevel(const int level);
        void setLevelCap(const int level_Cap);


        void gainExp(const int exp);
        void loseExp(const int exp);

        void updateLevel(const bool up = true);
        void update();

    private:
        int type;
        int level;
        int levelCap;
        int exp;
        int expNext;
    };

    std::vector<Skill> skills;

};


#endif //DRAGHI_E_SOTTERRANEI_SKILLCOMPONENT_H
