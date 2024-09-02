// Author: Pratyay Roy
#include <bits/stdc++.h>

using namespace std;

class Chakravyuh
{
private:
    vector<int> enemy_rings; // 11 rings of enemy with 0th ring being the innermost ring
    int initial_power;       // Initial power of the player
    int skips;               // Number of skips
    int recharges;           // Number of recharges

    void heal(int &curr_power, int &recharges_left)
    {
        curr_power = initial_power;
        recharges_left--;
        return;
    }

    void battle(int &curr_position,
                int &curr_power,
                int &last_skip)
    {
        curr_power -= enemy_rings[curr_position];
        if (curr_position == 4 && last_skip == 3)
            curr_power -= enemy_rings[3] / 2;
        if (curr_position == 7 && last_skip == 6)
            curr_power -= enemy_rings[6] / 2;
        curr_position++;
        return;
    }

    void skip(int &curr_position,
              int &skips_left,
              int &last_skip)
    {
        last_skip = curr_position;
        curr_position++;
        skips_left--;
        return;
    }

    bool shouldBattle(int &curr_position,
                      int &curr_power,
                      int &skips_left,
                      int &recharges_left,
                      int &last_skip)
    {
        if (curr_power < enemy_rings[curr_position])
        {
            if (recharges_left <= 0)
                return false;
            heal(curr_power, recharges_left);
        }
        battle(curr_position, curr_power, last_skip);
        if (curr_position >= 11)
            return true;
        return canCrossChakravyuh(curr_position,
                                  curr_power,
                                  skips_left,
                                  recharges_left,
                                  last_skip);
    }

    bool shouldSkip(int &curr_position,
                    int &curr_power,
                    int &skips_left,
                    int &recharges_left,
                    int &last_skip)
    {
        if (skips_left <= 0)
            return false;
        if (curr_position >= 10)
            return true;
        skip(curr_position, skips_left, last_skip);
        return canCrossChakravyuh(curr_position,
                                  curr_power,
                                  skips_left,
                                  recharges_left,
                                  last_skip);
    }

    bool canCrossChakravyuh(int curr_position,
                            int curr_power,
                            int skips_left,
                            int recharges_left,
                            int last_skip)
    {
        bool should_battle = shouldBattle(curr_position,
                                          curr_power,
                                          skips_left,
                                          recharges_left,
                                          last_skip);
        bool should_skip = shouldSkip(curr_position,
                                      curr_power,
                                      skips_left,
                                      recharges_left,
                                      last_skip);

        return should_battle || should_skip;
    }

public:
    // Constructor
    Chakravyuh(vector<int> &enemy_rings,
               int &initial_power,
               int &skips,
               int &recharges)
    {

        this->enemy_rings = enemy_rings;
        this->initial_power = initial_power;
        this->skips = skips;
        this->recharges = recharges;
    }

    bool solve()
    {
        int curr_position = 0;
        int curr_power = initial_power;
        int skips_left = skips;
        int recharges_left = recharges;
        int last_skip = -1;

        return canCrossChakravyuh(curr_position,
                                  curr_power,
                                  skips_left,
                                  recharges_left,
                                  last_skip);
    }
};

int main()
{
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        vector<int> enemy_rings;
        int initial_power, skips, recharges;

        /*
        Example input:
        1 2 3 4 5 6 7 8 9 10 11
        100 2 3
        */
        for (int i = 0; i < 11; i++)
        {
            int ring;
            cin >> ring;
            enemy_rings.push_back(ring);
        }
        cin >> initial_power >> skips >> recharges;

        Chakravyuh *chakravyuh = new Chakravyuh(enemy_rings,
                                                initial_power,
                                                skips,
                                                recharges);
        cout << chakravyuh->solve() << endl;
    }
    return 0;
}
