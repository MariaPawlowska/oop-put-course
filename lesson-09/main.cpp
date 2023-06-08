#include <iostream>
#include <vector>
#include <algorithm>

// IntegerSequence interface
class IntegerSequence {
public:
    virtual std::vector<int> Numbers() = 0;
};
// Concrete component: VectorSequence
class VectorSequence : public IntegerSequence {
private:
    std::vector<int> numbers;

public:
    VectorSequence(const std::vector<int>& nums) : numbers(nums) {}

    std::vector<int> Numbers() override {
        return numbers;
    }
};
// Decorator: PositiveSequence
class PositiveSequence : public IntegerSequence {
private:
    IntegerSequence* sequence;

public:
    PositiveSequence(IntegerSequence* seq) : sequence(seq) {}

    std::vector<int> Numbers() override {
        std::vector<int> original = sequence->Numbers();
        std::vector<int> result;

        for (int num : original) {
            if (num >= 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};
// Decorator: EvenSequence
class EvenSequence : public IntegerSequence {
private:
    IntegerSequence* sequence;

public:
    EvenSequence(IntegerSequence* seq) : sequence(seq) {}

    std::vector<int> Numbers() override {
        std::vector<int> original = sequence->Numbers();
        std::vector<int> result;

        for (int num : original) {
            if (num % 2 == 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};
// Decorator: SortedSequence
class SortedSequence : public IntegerSequence {
private:
    IntegerSequence* sequence;

public:
    SortedSequence(IntegerSequence* seq) : sequence(seq) {}

    std::vector<int> Numbers() override {
        std::vector<int> original = sequence->Numbers();
        std::vector<int> result = original;

        std::sort(result.begin(), result.end());

        return result;
    }
};

int main() {
    std::vector<int> numbers = {5, -3, 10, 2, -8, 7};
    // Create VectorSequence object
    IntegerSequence* sequence = new VectorSequence(numbers);
    // Apply decorators
    IntegerSequence* decoratedSequence = new PositiveSequence(new EvenSequence(new SortedSequence(sequence)));
    // Get processed numbers
    std::vector<int> processedNumbers = decoratedSequence->Numbers();
    // Print the result
    for (int num : processedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // Clean up
    delete decoratedSequence;
    delete sequence;

    return 0;
}

