






#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

struct Solution { }

impl Solution {
    pub fn swap_pairs(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut point = &mut head;
        loop {
            if point.is_none() {break;}
            if point.as_ref().unwrap().next.is_none() {break;}
            let mut x = point.take().unwrap();
            let mut y = x.next.unwrap();
            x.next = y.next.take();
            y.next = Some(x);
            *point = Some(y);
            point = &mut point.as_mut().unwrap().next.as_mut().unwrap().next;
        }
        head
    }
}
