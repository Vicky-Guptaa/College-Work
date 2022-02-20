Node *sortedMerge(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *curr = head;
    while (head1 && head2)
    {
        Node *temp = NULL;
        if (head1->data > head2->data)
        {
            temp = new Node(head2->data);
            head2 = head2->next;
        }
        else
        {
            temp = new Node(head1->data);
            head1 = head1->next;
        }
        if (head)
        {
            curr->next = temp;
            curr = curr->next;
        }
        else
        {
            head = temp;
            curr = head;
        }
    }
    while (head1)
    {
        Node *temp = new Node(head1->data);
        if (head)
        {
            curr->next = temp;
            curr = curr->next;
        }
        else
        {
            head = temp;
            curr = head;
        }
    }
    while (head2)
    {
        Node *temp = new Node(head2->data);
        if (head)
        {
            curr->next = temp;
            curr = curr->next;
        }
        else
        {
            head = temp;
            curr = head;
        }
    }
    return head;
}