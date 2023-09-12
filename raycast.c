/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:28:01 by rouali            #+#    #+#             */
/*   Updated: 2023/09/09 15:33:03 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// struct player
// {
//     float x;
//     float y;
//     float width;
//     float height;
//     int turnDirection; // -1 for left, +1 for right
//     int walkDirection; // -1 for back, +1 for front
//     float rotationAngle;
//     float walkSpeed;
//     float turnSpeed;
// } player;

// struct ray
// {
//     float rayAngle;
//     float wallHitX;
//     float wallHitY;
//     float distance;
//     int wasHitVertical;
//     int isRayFacingUp;
//     int isRayFacingDown;
//     int isRayFacingLeft;
//     int isRayFacingRight;
// } rays;

// float normalizeAngle(float angle)
// {
//     angle = remainder(angle, TWO_PI);
//     if (angle < 0)
//         angle = TWO_PI + angle;
//     return angle;
// }

// void castRay(float rayAngle, int stripld)
// {
//     rayAngle = normalizeAngle(rayAngle);
    
//     var xinitercept, yintercept;
//     var xstep, ystep;
    
//     ///////////////////////////////////////////
//     // HORIZONTAL RAY-GRID INTERSECTION CODE
//     ///////////////////////////////////////////
//     var foundHorzWallHit = false;
//     var horzWallHitX = 0;
//     var horzWallHitY = 0;
    
//     // Find the y-coordinate of the closest horizontal grid intersection
//     yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
//     yintercept += isRayFacingDown ? TILE_SIZE : 0;
    
//     // Find the x-coordinate of the closest horizontal grid intersection
//     xintercept = player.x + (yintercept - player.y) / tan(rayAngle);
    
//     // Calculate the increment xstep and ystep
//     ystep = TILE_SIZE;
//     ystep *= isRayFacingUp ? -1 : 1;
    
//     xstep = TILE_SIZE / tan(rayAngle);
//     xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
//     xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;
    
//     var nextHorzTouchX = xintercept;
//     var nextHorzTouchY = yintercept;
    
//     // Increment xstep and ystep until we find a wall
//     while (nextHorzTouchX >= 0 && nextHorzTouchX < WINDOW_WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY < WINDOW_HEIGHT)
//     {
//         if (mapHasWallAt(nextHorzTouchX, nextHorzTouchY - (isRayFacingUp ? 1 : 0)))
//         {
//             // found a wall hit
//             horzWallHitX = nextHorzTouchX;
//             horzWallHitY = nextHorzTouchY;
//             foundHorzWallHit = true;
//             break;
//         }
//         else
//         {
//             nextHorzTouchX += xstep;
//             nextHorzTouchY += ystep;
//         }
//     }
// }

// void castAllRays(t_vars *vars)
// {
//     float rayAngle = player.rotationAngle - (vars->fov / 2);
//     int i = 0;
//     while (i < 600)
//     {
//         castRay(rayAngle);
//         rayAngle += vars->fov / 600;
//         i++;
//     }
// }

















































