#ifndef COMMANTRIENODE_H
#define COMMANTRIENODE_H


#include <optional>
#include <unordered_map>
#include <memory>
#include <string>

class CommandTrieNode: public std::enable_shared_from_this<CommandTrieNode>
{
public:
    ///CHANGE IMPLEMENTATION SO THAT ITS CASE INSENSITIVE!!!

    CommandTrieNode();
    void insert(const std::string& command);
    bool noChildNode(const char& letter) const;
    void insertChildNode(const char& letter);
    std::shared_ptr<CommandTrieNode> getChildNode(const char& letter) const;
    void setEndOfCommand(const bool& val);
    /**
     * @brief findFirstMatch
     * @param command
     * @param executeFunction
     * @return
     *  int in the pair can be 0, 1, 2, or 3:
     *      0 -> the string returned is not a command and there is no command starting with this command paramter
     *      1 -> the string returned is a command, and there are no other commands starting with the returned string
     *      2 -> the string returned is not a command, but there are other commands starting with the returned string
     *      3-> the string returned is a command, and there are other commands starting with the returned string
     */
    std::pair<std::optional<std::string>, bool> findFirstMatch(const std::string& command, const bool& executeFunction);//RETURN VAL SAYS: OPTIONAL STRING FOR IF INPUT IS A COMMAND, OR IF THERE IS JUST ONE COMMAND THAT STARTS WITH THE INPUT THE FULL COMMAND IS RETURNED. IF THE INPUT IS A COMMAND, BUT THERE AE LONGER ONES THE BOOL IS FALSE. IF THE COMMAND IS IN THERE, BUT NOT FULL THE COMMAND IS TRUE.
    int getNumChildren() const;
    bool getIsEndOfCommand() const;

    std::unordered_map<char, std::shared_ptr<CommandTrieNode> > getChildNodes() const;

private:
    bool isEndOfCommand {false};
    std::unordered_map<char, std::shared_ptr<CommandTrieNode>> childNodes;

};

#endif // COMMANTRIENODE_H
