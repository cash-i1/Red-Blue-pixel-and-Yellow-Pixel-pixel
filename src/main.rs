use std::{cell, process::exit, usize};
use macroquad::prelude::*;

const scr_width: f32 = 1000.;
const scr_height: f32 = 100.;

const cell_size: usize = 10;

const grid_width: usize = scr_width as usize/ cell_size;
const grid_height: usize = scr_height as usize / cell_size;

#[derive(Clone, Copy, PartialEq)]
enum ptype {
    NONE = 0,
    RED = 1,
    BLUE = 2,
    YELLOW = 3,
}

#[macroquad::main("RBraYPp")]
async fn main() {
    let mut board: Vec<Vec<ptype>> = vec![vec![ptype::NONE; grid_height as usize]; grid_width as usize];
    request_new_screen_size(scr_width, scr_height);
    
    // Initializing the array
    for x in 0..grid_height as usize {
        for y in 0..grid_height as usize {
            if y % 2 == 1 {
                board[x][y] = ptype::RED;
            } else {
                board[x][y] = ptype::NONE;
            }
        }
    }

    loop {
        clear_background(BLACK);
       
        if is_mouse_button_down(MouseButton::Left) {
            board[mouse_position().0 as usize / cell_size][mouse_position().1 as usize / cell_size] = ptype::RED;
        }

        println!("{}", mouse_position().0 as usize / cell_size as usize);
        for row in 0..board.len() {
            for col in 0..board[row].len() {
                if board[row][col] == ptype::RED {
                    draw_rectangle((row * cell_size as usize) as f32, (col * cell_size as usize) as f32, cell_size as f32, cell_size as f32, RED);
                }
            }
        }
        

        draw_text(&get_fps().to_string(), 10., 10., 20., BLUE);

        // println!("width, {}, height, {}", screen_width(), screen_height());
        // println!("{}x{}", screen_width() as i32 / cell_size, screen_height() as i32 / cell_size);
        
        next_frame().await;
    } 
}
