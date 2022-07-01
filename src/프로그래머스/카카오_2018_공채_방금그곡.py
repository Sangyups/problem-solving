def get_melody(m):
    melody = []
    for i in range(len(m)):
        if m[i] == "#":
            continue
        temp = ""
        temp += m[i]
        if i < len(m) - 1 and m[i + 1] == "#":
            temp += m[i + 1]
        melody.append(temp)

    return melody


def solution(m, musicinfos):
    candidates = []
    listened_melody = get_melody(m)

    for order, music_info in enumerate(musicinfos):
        start_time, end_time, title, notes = music_info.split(",")
        start_time = sum(
            [
                int(time) * 60 if i == 0 else int(time)
                for i, time in enumerate(start_time.split(":"))
            ]
        )
        end_time = sum(
            [
                int(time) * 60 if i == 0 else int(time)
                for i, time in enumerate(end_time.split(":"))
            ]
        )
        elapsed_time = end_time - start_time

        total_notes = []
        notes = get_melody(notes)

        for i in range(elapsed_time):
            total_notes.append(notes[i % len(notes)])

        appended = 0
        for i in range(len(total_notes) - len(listened_melody) + 1):
            if appended:
                break
            flag = 0
            for j in range(len(listened_melody)):
                if total_notes[i + j] != listened_melody[j]:
                    flag = 1
                    break
            if flag:
                continue
            candidates.append([elapsed_time, order, title])
            appended = 1

    return (
        sorted(candidates, key=lambda x: (-x[0], x[1]))[0][2]
        if candidates
        else "(None)"
    )
