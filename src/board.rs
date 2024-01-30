use crate::particle::{self, Particle};
use macroquad::prelude::*;

pub struct Board {
    pub board_vect: Vec<Vec<particle::Particle>>,
    pub size: (i32, i32),
    
}

impl Board {
    pub fn new(size: (i32, i32)) -> Self {
        let board_vect = vec![vec![]; size.0 as usize];
        Board {
            board_vect,
            size,
        }
    }

    pub fn init(&mut self) {
        let grid_width = self.size.0;
        let grid_height = self.size.1;
        
        for row in 0..grid_width as i32 {
            for col in 0..grid_width {
                let pos = vec2(row as f32, col as f32);
                &self.board_vect[row as usize][col as usize] = &Particle::new(pos);

            }
        }
    } 

}
