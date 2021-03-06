import React from "react";
import { useDispatch } from "react-redux";
import { List, Icon, Button } from "semantic-ui-react";
import { removeFromTracks } from "../../store/tracks/actions";
import { AddToPlaylist } from "./Track/AddToPlaylist";

import classes from "./Track.module.css";

export function Track({ track }) {
  const { artist = "Unknown", title, length } = track;
  const dispatch = useDispatch();

  function handleDeleteClick(track) {
    dispatch(removeFromTracks(track));
  }

  return (
    <List.Item className={classes.track}>
      <List.Content floated="right" className={classes.actions}>
        <AddToPlaylist trackId={track._id} />
        <Button
          size="tiny"
          icon="trash"
          onClick={() => handleDeleteClick(track)}
        />
      </List.Content>
      <List.Icon verticalAlign="middle">
        <Icon size="large" color="violet" name="music" />
      </List.Icon>
      <List.Content>
        <List.Header>
          {artist} - {title || "No title provided"}
        </List.Header>
        <List.Description>{length || "Unknown length"}</List.Description>
      </List.Content>
    </List.Item>
  );
}
