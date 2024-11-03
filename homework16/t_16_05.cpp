#include <iostream>
#include <string>

class Word {
protected:
    std::string prefix;
    std::string prefix2;
    std::string root;
    std::string suffix;
    std::string ending;

public:
    Word(std::string prefix, std::string prefix2, std::string root, std::string suffix, std::string ending)
        : prefix(prefix), prefix2(prefix2), root(root), suffix(suffix), ending(ending) {}

    virtual std::string gender() { return ""; }
    virtual std::string number() { return ""; }
    virtual std::string person() { return ""; }
    virtual std::string caseForm() { return ""; }

    virtual std::string getWord() {
        return prefix + prefix2 + root + suffix + ending;
    }
};

class Noun : public Word {
public:
    Noun(std::string prefix, std::string prefix2, std::string root, std::string suffix, std::string ending)
        : Word(prefix, prefix2, root, suffix, ending) {}

    std::string number() override {
        return root + suffix + "s"; // example of plural form
    }

    std::string caseForm() override {
        return "Nominative"; // returns case
    }
};

class Verb : public Word {
public:
    Verb(std::string prefix, std::string prefix2, std::string root, std::string suffix, std::string ending)
        : Word(prefix, prefix2, root, suffix, ending) {}

    std::string person() override {
        return "Third person"; // example for third person
    }

    std::string number() override {
        return root + suffix + "es"; // example of plural form
    }
};

class Adjective : public Word {
public:
    Adjective(std::string prefix, std::string prefix2, std::string root, std::string suffix, std::string ending)
        : Word(prefix, prefix2, root, suffix, ending) {}

    std::string gender() override {
        return "Masculine"; // example for gender
    }

    std::string caseForm() override {
        return "Nominative"; // returns case
    }
};

int main() {
    Noun n("pre", "", "house", "", "");
    Verb v("", "", "go", "", "");
    Adjective adj("", "", "big", "", "");

    std::cout << "Noun: " << n.getWord() << ", plural: " << n.number() << std::endl;
    std::cout << "Verb: " << v.getWord() << ", third person: " << v.person() << ", plural: " << v.number() << std::endl;
    std::cout << "Adjective: " << adj.getWord() << ", gender: " << adj.gender() << std::endl;

    return 0;
}
