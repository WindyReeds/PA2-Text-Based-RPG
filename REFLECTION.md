1. For every function you wrote (TODO 1 to 19), explain in your own words what it does and give its time complexity in terms of n, the number of scenes. One short paragraph each.
   1. TODO 1: Constructor that initializes a Scene object with data_, choices_, and numChoices_. One for loop, so O(n) time.
   2. TODO 2: Destructor that frees everything in the scene. No loops so O(1) time.
   3. TODO 3: Checks whether the given scene has numChoices == 0. No loops so O(1) time.
   4. TODO 4: Gets scene at given index. No loops so O(1) time.
   5. TODO 5: Assigns given scene to the given index. No loops so O(1) time.
   6. TODO 6: Counts the number of scenes following and including the given scene. Recursive loop, so O(n) time.
   7. TODO 7: Counts the number of scenes with 0 choices. Recursive loop, so O(n) time.
   8. TODO 8: Returns the maximum height of the StoryTree. Recursive loop, so O(n) time.
   9. TODO 9: Frees every scene. Recursive loop, so O(n) time.
   10. TODO 10: Loads the story file, assigns the starting HP value to startHp_ and the root scene to root_. No loops, so O(1) time.
   11. TODO 11: Reads each field of each scene and assigns them to a new Moment. Recursive loop, so O(n) time.
   12. TODO 12: Gets user input and only accepts integers within the given range. Loop only executes on invalid input, so O(1).
   13. TODO 13: Runs each scene from the root, keeping track of HP, loot, and item changes. Method itself is O(1), but relies on helper methods running in O(n).
   14. TODO 14: Uses helper methods inside of StoryTree.h to print the number of scenes, endings, and maximum height respectively. No loops, so O(1) time.
   15. TODO 15: Prints every ending in the StoryTree. Recursive loop, so O(n) time.
   16. TODO 16: Prints every ending following a given scene. Recursive loop, so O(n) time.
   17. TODO 17: Automatically runs through the StoryTree, always making the choice that immediately gives the most loot. For loop, so O(n) time.
   18. TODO 18: Automatically runs down from a given scene, looking ahead and choosing the route that maximizes loot without dying. Recursive loop, so O(n) time.
   19. TODO 19: Same as bestLoot (above), but runs from the root. Recursive loop, so runs in O(n) time.
2. Why does each scene allocate exactly numChoices slots instead of declaring Scene<T>* choices[3]? What does an ending hold in choices_, and why?
   1. There is a variable number of choices between scenes, and we also use the number of scenes to determine whether it's an ending.
3. Walk through your Scene destructor. What gets deleted, and in what order? What would go wrong if choices_ were deleted first?
   1. I first deleted data_, then choices_, then assigned each a nullptr and set numChoices to 0. If we deleted choices_ first, we would lose track of the following scenes.
4. Show the path greedy took and the path optimal took on your story, with the loot for each. Explain why greedy lost. If greedy did not lose, change your story until it does, and explain what you changed.
   1. //
5. bestLoot tries every path, yet it runs in O(n) time. Explain why it is not exponential, using what you know about paths and leaves in a tree.
   1. //
6. Which List methods does your game use, and why? What does one search cost as the bag grows?
   1. I used addFront() to add items and search() to find them. search() runs in O(n) time. 