/**
 * @file
 * @brief Functions used in Pandemonium.
**/

#include "AppHdr.h"

#include "lev-pand.h"

#include <algorithm>

#include "colour.h"
#include "env.h"
#include "tileview.h"

static colour_t _pan_floor_colour()
{
    colour_t col;

    do
    {
        col = random_colour();
    }
    // Don't use silence or halo colours for floors.
    while (col == DARKGREY || col == CYAN || col == YELLOW);

    return col;
}

static colour_t _pan_rock_colour()
{
    colour_t col;

    do
    {
        col = random_colour();
    }
    // Don't use stone or metal colours for walls.
    while (col == DARKGREY || col == LIGHTGREY || col == CYAN);

    return col;
}

void init_pandemonium()
{
    for (int pc = 0; pc < PAN_MONS_ALLOC; ++pc)
    {
        env.mons_alloc[pc] = random_choose_weighted(5, MONS_GNOLL,
                                                    5, MONS_GNOLL,
                                                    5, MONS_GNOLL,
                                                    5, MONS_GNOLL,
                                                    5, MONS_GNOLL,
                                                    5, MONS_GNOLL,
                                                    2, MONS_GNOLL,
                                                    5, MONS_GNOLL,
                                                    1, MONS_GNOLL,
                                                    1, MONS_GNOLL,
                                                    1, MONS_GNOLL,
                                                    1, MONS_GNOLL,
                                                    1, MONS_GNOLL,
                                                    0);

        // The last three slots have a good chance of big badasses.
        if (pc == 7 && one_chance_in(8)
         || pc == 8 && one_chance_in(5)
         || pc == 9 && one_chance_in(3))
        {
            env.mons_alloc[pc] = random_choose_weighted(
                  4, MONS_GNOLL,
                  4, MONS_GNOLL,
                  4, MONS_GNOLL,
                  4, MONS_GNOLL,
                  4, MONS_GNOLL,
                  2, MONS_GNOLL,
                  2, MONS_GNOLL,
                  2, MONS_GNOLL,
                  2, MONS_GNOLL,
                  0);
        }
    }

    if (one_chance_in(10))
        env.mons_alloc[7 + random2(3)] = MONS_GNOLL;

    if (one_chance_in(10))
        env.mons_alloc[7 + random2(3)] = MONS_GNOLL;

    if (one_chance_in(10))
        env.mons_alloc[7 + random2(3)] = MONS_GNOLL;

    if (one_chance_in(10))
        env.mons_alloc[7 + random2(3)] = MONS_GNOLL;

    if (one_chance_in(10))
        env.mons_alloc[7 + random2(3)] = MONS_GNOLL;

    env.floor_colour = _pan_floor_colour();
    env.rock_colour  = _pan_rock_colour();
    tile_init_default_flavour();
}
