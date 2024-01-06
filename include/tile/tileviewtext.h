#ifndef TILEVIEWTEXT_H
#define TILEVIEWTEXT_H


#include "tilemodel.h"
#include "tileview.h"
#include "qplaintextedit.h"
#include <memory>

/**
 * @class TileViewText
 * @brief Class responsible for text display of tiles in the game
 */
class TileViewText: public TileView
{
public:
    /**
     * @brief Default constructor for the TileViewText class.
     * Initializes a TileViewText instance.
     */
    TileViewText();

    /**
     * @brief Updates the text-based view with the tile grid information or adjusts the cursor position.
     * @param row Row index for the tile grid.
     * @param col Column index for the tile grid.
     * If 'displayed' flag is set, adjusts the cursor position based on the provided row and column.
     * Otherwise, generates a textual representation of the tile grid and sets it as the text edit content.
     * Adjusts the cursor position in the text edit.
     */
    void update(int row = 0, int col = 0) override;

    /**
     * @brief Clears the text-based view and resets the 'displayed' flag.
     * Resets the 'displayed' flag to false and resets the text edit.
     */
    void clearView() override;

    /**
     * @brief Sets the TileModel for the text-based view.
     * @param newTileModel Shared pointer to the new TileModel to be set.
     * Assigns the provided TileModel to the tileModel member variable.
     */
    void setTileModel(const std::shared_ptr<TileModel> &newTileModel) override;

    /**
     * @brief Sets the text edit component for the text-based view.
     * @param newTextEdit Shared pointer to the new QPlainTextEdit to be set.
     * Assigns the provided QPlainTextEdit to the textEdit member variable.
     */
    void setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit);

private:
    std::shared_ptr<QPlainTextEdit> textEdit; /**< Shared pointer to the QPlainTextEdit component for textual display. */
    bool displayed {false}; /**< Flag indicating if the text is displayed. Default value: false */
};

#endif // TILEVIEWTEXT_H
