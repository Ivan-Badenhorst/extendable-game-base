#ifndef TILEVIEWGRAPHICAL_H
#define TILEVIEWGRAPHICAL_H

#include "qgraphicsscene.h"
#include "tilemodel.h"
#include "tileview.h"

#include <memory>

/**
 * @class TileViewGraphical
 * @brief Class responsible for graphical display of tiles in the game
 */
class TileViewGraphical: public TileView
{
public:
    TileViewGraphical();

    /**
     * @brief Updates the graphical view based on the current position.
     * @param positionRow Row index for the current position.
     * @param positionCol Column index for the current position.
     */
    void update(int row = 0, int col = 0) override;

    /**
     * @brief Clears the graphical view.
     * Clears all displayed items from the scene.
     */
    void clearView() override;

    /**
     * @brief Sets the QGraphicsScene for the TileViewGraphical.
     * @param newScene Shared pointer to the new QGraphicsScene.
     */
    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

    /**
     * @brief Sets the TileModel for the TileViewGraphical.
     * @param newTileModel Shared pointer to the new TileModel.
     */
    void setTileModel(const std::shared_ptr<TileModel> &newTileModel) override;

private:
    int prevRow {-1}; /**< Previous row index. Default value: -1 */
    int prevCol {-1}; /**< Previous column index. Default value: -1 */
    int tileDim {50}; /**< Dimension of each tile. Default value: 50 */


    int displayWidth {16}; /**< Width of the display in number of tiles. Default value: 16 */
    int displayHeight {8}; /**< Height of the display in number of tiles. Default value: 8 */

    bool portalsDisplayed {false}; /**< Indicates if portals are displayed. Default value: false */
    std::vector<std::shared_ptr<QGraphicsPixmapItem>> tileDisplays; /**< Vector of shared pointers to QGraphicsPixmapItem for tile display */
    std::vector<std::vector<bool>> hasBeenRendered; /**< 2D vector tracking rendered tiles */

    /**
     * @brief Displays a section of tiles within the specified range.
     * @param rowStart Starting row index for the display.
     * @param rowEnd Ending row index for the display.
     * @param colStart Starting column index for the display.
     * @param colEnd Ending column index for the display.
     */
    void displaySection(int rowStart, int rowEnd, int colStart, int colEnd);

    std::shared_ptr<QGraphicsScene> scene;

    /**
     * @brief Returns an icon based on the given range.
     * @param range Range value determining the icon.
     * @return Shared pointer to a QPixmap representing the icon.
     */
    std::shared_ptr<QPixmap> getIcon(int range);

    /**
     * @brief Adds a portal image at the specified row and column.
     * @param row Row index for the portal image.
     * @param col Column index for the portal image.
     */
    void AddPortalImage(int row, int col);

    /**
     * @brief Updates the opacity for visited tiles within the rendered area.
     * Uses information from the TileModel to update displayed tile opacities.
     */
    void updateOpacityInRenderedArea();
};

#endif // TILEVIEWGRAPHICAL_H
