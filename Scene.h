#pragma once

// One scene of the story and the doors leading out of it.
//
// RULES (do not change):
//   - Keep every member variable, name, and signature exactly as written.
//   - choices_ must stay a double pointer: Scene<T>** choices_.
//   - No std::vector, no std::array, no fixed-size array like choices_[3].
//   - The scene OWNS data_ and every scene its slots point to.
template <typename T>
class Scene {
private:
    T* data_;
    Scene<T>** choices_;
    int numChoices_;

public:
    static const int MAX_CHOICES = 3;

    Scene(T* data, int numChoices) : data_(data), choices_(nullptr), numChoices_(numChoices) {
        // TODO 1: Done
        // A scene with numChoices_ choices needs exactly numChoices_ slots.
        // An ending (0 choices) needs no slots at all.
        // Every slot must start out empty.

        if (numChoices_ == 0) {
            choices_ = nullptr;
            return;
        }
        choices_ = new Scene<T>*[numChoices];
        for (int i = 0; i < numChoices; i++) {
            choices_[i] = nullptr;
        }
    }

    ~Scene() {
        // TODO 2: Done
        // Free everything this scene owns.
        // Think about what it owns, and what each slot points to.

        delete data_;
        delete[] choices_;
        data_ = nullptr;
        choices_ = nullptr;
        numChoices_ = 0;
    }

    T* getData() const {
        return data_;
    }

    int getNumChoices() const {
        return numChoices_;
    }

    // TODO 3: Done
    // True if this scene is an ending.
    bool isEnding() const {
        if (numChoices_ == 0) {
            return true;
        }
        return false;
    }

    // TODO 4: Done
    // The scene behind slot index.
    // Return nullptr if index is not a real slot.
    Scene<T>* getChoice(int index) const {
        if (index >=0 && index < numChoices_) {
            return choices_[index];
        }
        return nullptr;
    }

    // TODO 5: Done
    // Put next into slot index.
    // Do nothing if index is not a real slot.
    void setChoice(int index, Scene<T>* next) {
        if (index >=0 && index < numChoices_) {
            choices_[index] = next;
        }
    }
};
