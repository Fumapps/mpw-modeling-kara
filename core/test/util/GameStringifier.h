#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_GAMESTRINGIFIER_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_GAMESTRINGIFIER_H

#include <memory>
#include <string>

#include "KaraGame.h"

namespace util {

/**
 * Helper class to serialize / deserialize KaraGame to / from Strings
 */
class GameStringifier {
public:
    GameStringifier() = delete;

    /**
     * Creates a KaraGame from the given String. The game will not be started.
     * @param map Encoded game, which uses the following characters
     *            '#' for a Tree
     *            '*' for a Leaf
     *            '@' for a Mushroom
     *            '<' '^' '>' 'v' for the default Kara in the related direction
     *            ';' for the end of a row
     */
    static std::shared_ptr<kara::KaraGame> createFromString(const std::string& map);

    /**
     * Creates a KaraGame from the given String and starts the game.
     * @param map Encoded game, which uses the following characters
     *            '#' for a Tree
     *            '*' for a Leaf
     *            '@' for a Mushroom
     *            '<' '^' '>' 'v' for the default Kara in the related direction
     *            ';' for the end of a row
     */
    static std::shared_ptr<kara::KaraGame> createFromStringStarted(const std::string& map);

    /**
     * Converts the given game to a simple String.
     *            '#' for a Wall
     *            '*' for a Leaf
     *            '@' for a Mushroom
     *            '<' '^' '>' 'v' for the default Kara in the related direction
     *            ';' for the end of a row
     * @return the encoded String for the game.
     */
    static std::string toString(const kara::KaraGame& game);

};

}


#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_GAMESTRINGIFIER_H
