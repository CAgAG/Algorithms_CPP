class Trie {
	class TrieNode {
		public boolean isLeaf;
		TrieNode[] nextNode;
		public TrieNode() {
			this.isLeaf = false;
			this.nextNode = new TrieNode[26];
		}
		public TrieNode addChild(Character c) {
			this.nextNode[c - 'a'] = new TrieNode();
			return this.nextNode[c - 'a'];
		}
		public TrieNode findChild(Character c) {
			return this.nextNode[c - 'a'];
		}

	}

	TrieNode root;

	public Trie() {
		this.root = new TrieNode();
	}

	public void insert(String word) {
		TrieNode cur = root;
		for (var c : word.toCharArray()) {
			TrieNode next = cur.findChild(c);
			if (next != null) {
				cur = next;
			} else {
				cur = cur.addChild(c);
			}
		}
		cur.isLeaf = true;
	}

	public boolean search(String word) {
		TrieNode cur = searchPrefix(word);
		return cur != null && cur.isLeaf;
	}

	public boolean startsWith(String prefix) {
		return searchPrefix(prefix) != null;
	}

	private TrieNode searchPrefix(String prefix) {
		TrieNode cur = root;
		for (var c : prefix.toCharArray()) {
			TrieNode next = cur.findChild(c);
			if (next == null) {
				return null;
			} else {
				cur = next;
			}
		}
		return cur;
	}
}