## Problem Statement

Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies.
Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back.

Given:

- Each circle is guarded by different enemy where enemy is equipped with `k1, k2……k11` powers.
- Abhmanyu starts from the innermost circle with `p` power.
- Abhimanyu has a boon to skip fighting enemy
  `a` times.
- Abhmanyu can recharge himself with power `b` times
- Battling in each circle will result in loss of the same power from Abhimanyu as the enemy.
- If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle.
- `k3` and `k7` enemies are endured with power to regenerate themselves once with half of their initial
  power and can attack Abhimanyu from behind if he is battling in iteratively next circle.

Write an algorithm to find if Abhimanyu can cross the Chakravyuh and test it with two sets of test cases.

## Assumptions

To fill in the gaps of the problem statement, I have taken the liberty to assume the following conditions:

- `k1` is the innermost circle, and `k11` is the outermost.
- Abhmanyu recharges himself fully upto his initial power `p` from any power value he currently has.
- The boon of the `k3` and `k7` enemies work even if they are skipped. (They will attack Abhimanyu from behind with half their power.)
- The `k3` and `k7` enemies will attack Abhimanyu even if he decides to skip the iteratively next circle.

## Algorithmic Analysis

At each circle, Abhimanyu has the choice of either `battling` or `skipping`.

1. Recursive Method: We use a recursive function to determine if Abhimanyu can cross the Chakravyuh. In the code, the function `canCrossChakravyuh()` is a recursive function, the functions `shouldBattle()` and `shouldSkip()` represent the two recursive branches.

## Technical Details

1. Time Complexity: O(2<sup>n</sup>), as there are two recursion branches.
2. Space Complexity: O(n) auxillary space as the recursive stack.
