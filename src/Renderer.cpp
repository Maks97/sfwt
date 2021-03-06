#include "Renderer.h"
#include "Chunk.h"
#include "Entity.h"
#include "Vector.h"

std::string render(Chunk chunk)
{
    std::string renderedMap;
    for(int y = 15; y >= 0; y--)
    {
        for(int x = 0; x <= 15; x++)
        {
            for(Entity *entity : chunk.entities)
            {
                FlooredVector nearestTile = entity->findFlooredCoordinates();
                if(nearestTile.x == x && nearestTile.y == y && nearestTile.z == 15)
                {
                    renderedMap.push_back(entity->character);
                    goto nextTile;
                }
            }
            if(chunk.tiles[x][y][15].isSloped())
                renderedMap.push_back('n');
            else
                renderedMap.push_back('O');

            nextTile:
            continue;
        }
        renderedMap.push_back('\n');
    }
    return renderedMap;
}
