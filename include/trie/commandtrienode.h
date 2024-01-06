/**
 * @file commandtrienode.h
 * @brief Declares the CommandTrieNode class.
 *
 * This file contains the declaration of the CommandTrieNode class,
 * which represents a node in a Trie structure used for command line operations.
 * It defines the interface for managing command sequences within the Trie structure.
 */

#ifndef COMMANDTRIENODE_H
#define COMMANDTRIENODE_H


#include <functional>
#include <optional>
#include <unordered_map>
#include <memory>
#include <string>


/**
 * @class CommandTrieNode
 * @brief Represents a node in a Trie structure used for command line operations.
 *
 * This class models a node in a Trie structure specifically designed for managing command sequences.
 * It encapsulates functions to store, retrieve, and execute commands represented by character sequences.
 * The node structure forms a hierarchical representation of possible command sequences and their associated actions.
 */
class CommandTrieNode: public std::enable_shared_from_this<CommandTrieNode>
{
public:

    /**
     * @brief Default constructor for CommandTrieNode.
     * Initializes a CommandTrieNode object.
     */
    CommandTrieNode();

    /**
     * @brief Inserts a command into the command trie along with its associated function.
     * @param command The command string to be inserted.
     * @param func The function associated with the command.
     *          Inserts a command into the command trie structure. It iterates through each character
     *          of the command, creating nodes if necessary, and finally marks the end of the command
     *          and assigns the provided function to that command.
     */
    void insert(const std::string& command, const std::function<void()>& func);

    /**
     * @brief Checks if a child node with the given letter exists.
     * @param letter The character representing the command.
     * @return True if the child node exists for the given letter, false otherwise.
     *          Checks whether a child node exists in the trie structure for the provided letter.
     */
    bool noChildNode(const char& letter) const;

    /**
     * @brief Inserts a child node with the given letter into the current node.
     * @param letter The character representing the command.
     *          Inserts a new child node into the current node for the provided letter.
     */
    void insertChildNode(const char& letter);

    /**
     * @brief Sets the end-of-command flag for the node.
     * @param val Boolean value to set the end-of-command flag.
     *            If true, signifies the end of a command sequence; otherwise, false.
     */
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
    std::pair<std::optional<std::string>, int> findFirstMatch(const std::string& command, const bool& executeFunction);

    /**
     * @brief Retrieves the number of children nodes for the current node.
     * @return The count of children nodes attached to the current node.
     *         Retrieves and returns the count of child nodes connected to the current node.
     */
    int getNumChildren() const;

    /**
     * @brief Checks if the current node represents the end of a command.
     * @return Boolean indicating whether the current node signifies the end of a command.
     *         Returns true if the current node marks the end of a command in the trie structure, otherwise returns false.
     */
    bool getIsEndOfCommand() const;

    /**
     * @brief Retrieves the child nodes of the current trie node.
     * @return An unordered map containing child nodes.
     *         Returns an unordered map where the keys are characters representing commands,
     *         and the values are shared pointers to the corresponding child nodes in the trie structure.
     */
    std::unordered_map<char, std::shared_ptr<CommandTrieNode> > getChildNodes() const;

    /**
     * @brief Retrieves the child node associated with the given letter.
     * @param letter The character you are searching for.
     * @return Shared pointer to the child node associated with the given letter.
     *         Retrieves the child node from the trie structure associated with the provided letter.
     *         If no node is found, returns a nullptr.
     */
    std::shared_ptr<CommandTrieNode> getChildNode(const char& letter) const;

    /**
     * @brief Sets the command function associated with the node.
     * @param newCommandFunction The function to be associated with the command node.
     *        Sets the function to be executed when the command is matched within the trie structure.
     */
    void setCommandFunction(const std::function<void ()> &newCommandFunction);

    /**
     * @brief Executes the associated command function.
     *        If a command function is associated with the node, it is executed.
     */
    void executeCommand();

    /**
     * @brief Retrieves all the stored commands within the Trie structure.
     * @return A vector containing all the commands stored in the Trie structure.
     */
    std::vector<std::string> getAllCommands() const;

private:
    bool isEndOfCommand {false}; /**< Indicates whether the node marks the end of a command sequence. Default: false */
    std::unordered_map<char, std::shared_ptr<CommandTrieNode>> childNodes; /**< Map of child nodes linked to this node based on character inputs */
    std::function<void()> commandFunction; /**< Function pointer to store the command action associated with this node */

};

#endif // COMMANDTRIENODE_H
