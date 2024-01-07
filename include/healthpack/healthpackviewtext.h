/**
 * @file healthpackviewtext.h
 * @brief Defines the HealthPackViewText class handling text-based display of health packs in the game.
 *
 * This file contains the declaration of HealthPackViewText, responsible for managing the textual representation
 * of health packs in the game environment, offering methods to update, clear, and set the associated health pack model.
 */

#ifndef HEALTHPACKVIEWTEXT_H
#define HEALTHPACKVIEWTEXT_H


#include "healthpackmodel.h"
#include "healthpackview.h"
#include "qplaintextedit.h"
#include <memory>
#include <mutex>

/**
 * @class HealthPackViewText
 * @brief Handles text-based display of health packs in the game.
 *
 * This class manages the textual representation of health packs in the game environment,
 * providing methods to update, clear, and set the associated health pack model.
 */
class HealthPackViewText: public HealthPackView
{
public:
    HealthPackViewText();

    /**
     * @brief Updates the textual representation of all health packs.
     * Calls the update function for each health pack's status.
     * If the health pack is unused, its status is displayed as 'H', otherwise as 'h'.
     */
    void update() override;

    /**
     * @brief Updates the text-based view with health pack information at the specified position.
     * @param row Row index for the health pack grid.
     * @param col Column index for the health pack grid.
     * @param used Flag indicating if the health pack is used or unused.
     *        If 'used' is true, 'h' is displayed, otherwise 'H' is displayed for an unused health pack.
     */
    void update(int row, int col,  bool used = true) override;

    /**
     * @brief Clears the text-based view of health pack representations.
     * Resets the text edit component.
     */
    void clearView() override;

    /**
     * @brief Sets the health pack model for the text-based view.
     * @param newHpModel Shared pointer to the new HealthPackModel to be set.
     * Assigns the provided HealthPackModel to the hpModel member variable.
     */
    void setHpModel(const std::shared_ptr<HealthPackModel> &newHpModel) override;

    /**
     * @brief Sets the text edit component for the text-based view.
     * @param newTextEdit Shared pointer to the new QPlainTextEdit to be set.
     * Assigns the provided QPlainTextEdit to the textEdit member variable.
     */
    void setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit);

private:
    std::shared_ptr<QPlainTextEdit> textEdit; /**< Shared pointer to the QPlainTextEdit component for textual display. */
};

#endif // HEALTHPACKVIEWTEXT_H
