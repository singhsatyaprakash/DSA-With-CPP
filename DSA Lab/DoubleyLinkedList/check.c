    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            // Swap prev and next for current node
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // Move to the next node (originally prev node)
            current = current->prev;
        }

        // If list is not empty, update head to the last node
        if (temp != nullptr) {
            head = temp->prev;
        }
    }