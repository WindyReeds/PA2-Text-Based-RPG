#pragma once
#include <algorithm>

#include "Scene.h"

// The whole story. It knows the first scene and nothing else.
//
// RULES (do not change):
//   - Keep every name and signature exactly as written.
//   - The private helpers must be recursive. No loops that walk down the tree.
//   - This class must work for ANY T. Never mention Moment in here.
template <typename T>
class StoryTree {
private:
    Scene<T>* root_;

    // TODO 6: how many scenes are in the story that starts at scene?
    // An empty story has 0 scenes.
    int countScenes(Scene<T>* scene) const {
        if (scene->getData() == nullptr) {
            return 1;
        }
        for (int i = 0; i < scene->getNumChoices(); i++) {
            return 1 + countScenes(scene->getChoice(i));
        }
    }

    // TODO 7: how many endings are in the story that starts at scene?
    int countEndings(Scene<T>* scene) const {
        if (scene->getData() == nullptr) {
            return 0;
        }
        if (scene->getNumChoices() == 0) {
            return 1;
        }
        for (int i = 0; i < scene->getNumChoices(); i++) {
            return countScenes(scene->getChoice(i));
        }
    }

    // TODO 8: the most choices a player can make on the way to an ending,
    // starting at scene. A single ending scene has height 0.
    // An empty story has height -1.
    int height(Scene<T>* scene) const {
        if (scene->getData() == nullptr) {
            return -1;
        }
        if (scene->getNumChoices() == 0) {
            return 0;
        }

        // Recursively traverse each branch. No branch = 0.
        int height[3] = { 0,0,0 };
        for (int i = 0; i < scene->getNumChoices(); i++) {
            height[i] = height[scene->getChoice(i)];
        }

        // Tally +1 for each non-ending scene, then return max of 3 branches.
        int maxHeight = std::max(height[0], height[1]);
        maxHeight = std::max(maxHeight, height[2]);
        return maxHeight + 1;
    }

public:
    StoryTree() : root_(nullptr) {}

    ~StoryTree() {
        clear();
    }

    void setRoot(Scene<T>* root) {
        clear();
        root_ = root;
    }

    Scene<T>* getRoot() const {
        return root_;
    }

    bool isEmpty() const {
        return root_ == nullptr;
    }

    // TODO 9: free every scene in the story and leave the tree empty.
    // Hint: what does deleting a Scene already do for you?
    void clear() {
    }

    int countScenes() const {
        return countScenes(root_);
    }

    int countEndings() const {
        return countEndings(root_);
    }

    int height() const {
        return height(root_);
    }
};
