#ifndef COMMANTRIENODE_H
#define COMMANTRIENODE_H


#include <unordered_map>
#include <memory>
#include <string>

class CommandTrieNode
{
public:
    CommandTrieNode();
    void insert(std::string& command);
    bool noChildNode(const char& letter) const;
    void insertChildNode(const char& letter);
    std::shared_ptr<CommandTrieNode> getChildNode(const char& letter) const;
    void setEndOfCommand(const bool& val);

private:
    bool isEndOfCommand {false};
    std::unordered_map<char, std::shared_ptr<CommandTrieNode>> childNodes;

};

#endif // COMMANTRIENODE_H
