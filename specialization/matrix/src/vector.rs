use std::ops::{Index, IndexMut};

pub struct Vector<K> {
    elements: Vec<K>,
}

impl<K> Vector<K> {
    pub fn new(elements: Vec<K>) -> Self {
        Vector { elements }
    }

    pub fn len(&self) -> usize {
        self.elements.len()
    }

    pub fn get(&self, index: usize) -> Option<&K> {
        self.elements.get(index)
    }
}

impl<K> Index<usize> for Vector<K> {
    type Output = K;

    fn index(&self, index: usize) -> &Self::Output {
        &self.elements[index]
    }
}

impl<K> IndexMut<usize> for Vector<K> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        &mut self.elements[index]
    }
}
