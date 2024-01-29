use macroquad::prelude::*;

pub struct Particle {
    pub pos: Vec2,
}

impl Particle {
    pub fn new(pos: Vec2) -> Self {
        Particle { pos }
    }
}
