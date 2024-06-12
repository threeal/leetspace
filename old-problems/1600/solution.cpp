#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class ThroneInheritance {
  struct Person {
    std::string name;
    bool alive;
    std::list<Person*> children;

    Person(const std::string& name) : name(name), alive{true}, children{} {}
  };

  Person king;
  std::unordered_map<std::string, Person*> personMap;
  std::size_t personCount;

 public:
  ThroneInheritance(std::string kingName) : king(kingName), personMap{}, personCount{1} {
    personMap.emplace(kingName, &king);
  }

  void birth(std::string parentName, std::string childName) {
    auto person = new Person(childName);
    ++personCount;

    personMap[parentName]->children.push_back(person);
    personMap.emplace(childName, person);
  }

  void death(std::string name) {
    personMap[name]->alive = false;
    --personCount;
  }

  std::vector<std::string> getInheritanceOrder() {
    std::vector<std::string> output(personCount);

    auto it = output.begin();
    getInheritanceOrder(it, &king);
    return output;
  }

 private:
  void getInheritanceOrder(std::vector<std::string>::iterator& it, Person* person) {
    if (person->alive) {
      *it = person->name;
      ++it;
    }

    for (const auto& child : person->children) {
      getInheritanceOrder(it, child);
    }
  }
};
