import { useState } from "react";
import "./App.css";
import Note from "./Note";

function App() {
  const [notes, setNotes] = useState([]);
  const [newNote, setNewNote] = useState({ title: "", text: "" });

  const addNote = () => {
    if (newNote.title && newNote.text) {
      const newId = Date.now().toString();
      setNotes([...notes, { ...newNote, id: newId }]);
      setNewNote({ title: "", text: "" });
    }
  };

  const deleteNote = (id) => {
    const updatedNotes = notes.filter((note) => note.id !== id);
    setNotes(updatedNotes);
  };

  const editNote = (id, newText) => {
    const updatedNotes = notes.map((note) =>
      note.id === id ? { ...note, text: newText } : note
    );
    setNotes(updatedNotes);
  };

  return (
    <div className="container">
      <h1>Notes App</h1>
      <div className="note-form">
        <input
          type="text"
          placeholder="Title"
          value={newNote.title}
          onChange={(e) => setNewNote({ ...newNote, title: e.target.value })}
        />
        <textarea
          rows="4"
          cols="50"
          placeholder="Text"
          value={newNote.text}
          onChange={(e) => setNewNote({ ...newNote, text: e.target.value })}
        />
        <button onClick={addNote}>Add Note</button>
      </div>

      <div className="App">
        <div className="note-list">
          {notes.map((note) => (
            <Note key={note.id} note={note} onDelete={deleteNote} onEdit={editNote} />
          ))}
        </div>
      </div>

    </div>
  );
}

export default App;