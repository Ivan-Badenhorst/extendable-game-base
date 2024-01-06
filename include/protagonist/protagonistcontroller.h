#ifndef PROTAGONISTCONTROLLER_H
#define PROTAGONISTCONTROLLER_H

#include "protagonistmodel.h"
#include "protagonistview.h"
#include <QObject>
#include <QTimer>


/**
 * @class ProtagonistController
 * @brief Controller for the protagonist in the game.
 *
 * This class is responsible for controlling and orchestrating the protagonist's actions, state, and display.
 * It uses a shared pointer to a ProtagonistModel object to get and update the protagonist's state.
 * It also uses a shared pointer to a ProtagonistView object to update the protagonist's view.
 * It inherits from QObject to use signals and slots.
 */
class ProtagonistController: public QObject
{
    Q_OBJECT
public:

    /**
     * @brief Constructor that initializes the protagonist model.
     * connects the timers to their respective slots
     * @param pm Shared pointer to the protagonist model.
     */
    ProtagonistController(std::shared_ptr<ProtagonistModel> pm);
 
     /**
     * @brief Generic refresh of the protagonist's view.
     */   
    void refreshAll();

    /**
     * @brief Updates the protagonist's position based on the move.
     * @param row The row position.
     * @param col The column position.
     */
    void update(int row, int col);

    
    /**
     * @brief Updates the protagonist's health.
     * Handles the event when the protagonist lands on a health pack.
     * @param hpValue The amount of health to be added.
     */
    void gainHealth(int hpValue);

    /**
     * @brief Handles the event when the protagonist takes damage.
     * @param hpValue The amount of damage taken.
     * @return True if the protagonist is dead, false otherwise.
     */
    bool takeDamage(int hpValue);

    /**
     * @brief Initiates the protagonist's attack.
     */
    void attackEnemy();

    /**
     * @brief Gets the protagonist's attack damage.
     * @return The protagonist's attack damage.
     */
    int getAttackDamage();

    /**
     * @brief Updates the protagonist's energy.
     * @param enValue The amount of energy to be updated.
     * @return True if the protagonist is dead, false otherwise.
     */
    bool updateEnergy(float enValue);

    /**
     * @brief Modifies a flag in the protagonistModel if they are in danger 
     * Updates the view to reflect this.
     * @param isInDanger True if the protagonist is in danger, false otherwise.
     */
    void updateWarning(bool isInDanger);

    /**
     * @brief Initiates the protagonist's death sequence.
     */
    void showDeath();

     /**
     * @brief Checks if the protagonist is dead.
     * @return True if the protagonist is dead, false otherwise.
     */
    bool getIsDead() const;


    /**
     * @brief Sets the protagonist's view.
     * @param newProtView Shared pointer to the new protagonist view.
     */
    void setProtView(const std::shared_ptr<ProtagonistView> &newProtView);

    /**
     * @brief Gets the protagonist's model.
     * @return Shared pointer to the protagonist's model.
     */
    std::shared_ptr<ProtagonistModel> getProtModel() const;

   
private:
    std::shared_ptr<ProtagonistView> protView;
    std::shared_ptr<ProtagonistModel> protModel;
    
    bool isDead;
    
//animation timers and flags

    QTimer attackTimer;
    QTimer healthGainTimer;
    QTimer deathTimer;
    QTimer takeDamageTimer;
    
    bool forwardAnimation{true};
    int currentFrame;


signals:

private slots:
    /**
     * @brief Handles the event when the protagonist's attack timer times out.
     * Calls the view to display the attack frame by frame
     * stops timer when the animation sequence is complete
     */
    void onAttackTimerTimeout();
    
    /**
     * @brief Handles the event when the protagonist's health gain timer times out.
     * Calls the view to display the health gain
     * stops timer when the animation sequence is complete
     */
    void onHealthGainTimerTimeout();

    /**
     * @brief Handles the event when the protagonist's death timer times out.
     * Calls the view to display the death animation frame by frame
     * stops timer when the animation sequence is complete
     */    
    void onDeathTimerTimeout();

    /**
     * @brief Handles the event when the protagonist's damage timer times out.
     * Calls the view to display the damage animation
     * stops timer when the animation sequence is complete
     */
    void onDamageTimerTimeout();

};

#endif // PROTAGONISTCONTROLLER_H
