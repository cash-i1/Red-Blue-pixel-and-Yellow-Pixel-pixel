use std::{cell, process::exit, usize};

use macroquad::prelude::*;

mod particle;

const scr_width: f32 = 1000.;
const scr_height: f32 = 100.;

const cell_size: i32 = 10;

const grid_width: i32 = scr_width as i32 / cell_size;
const grid_height: i32 = scr_height as i32 / cell_size;


#[macroquad::main("RBraYPp")]
async fn main() {
    let mut board: Vec<Vec<i32>> = Vec::new();
    request_new_screen_size(scr_width, scr_height);
    for _ in 0..screen_width() as i32 {
        let mut row: Vec<i32> = Vec::new();
        
        for i in 0..grid_height {
            if i % 2 == 1 {
                row.push(1);
            } else {

                row.push(0);
            }
        }
        board.push(row);
    }

    loop {
        board.reserve((screen_height() as usize / cell_size as usize) as usize - board.len() as usize); 
        clear_background(BLACK);
       
        if is_mouse_button_down(MouseButton::Left) {
            board[mouse_position().0 as usize / cell_size as usize][mouse_position().1 as usize / cell_size as usize] = 1;
        }
        println!("{}", mouse_position().0 as usize / cell_size as usize);
        for row in 0..board.len() {
            for col in 0..board[row].len() {
                if board[row][col] == 1 {

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
